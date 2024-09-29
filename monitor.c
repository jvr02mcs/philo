#include "philo.h"

int     is_everyone_alive(t_philo *philo)
{
        int     ret;

        ret = 1;
        pthread_mutex_lock(&(philo->data->mtx));
        if (philo->data->someone_dead)
                ret = 0;
        pthread_mutex_unlock(&(philo->data->mtx));
        return (ret);
}

void    check_death_time(t_philo *philo, int n)
{
        int                     i;
        uint64_t        time;

        i = 0;
        while (i < n)
        {
                pthread_mutex_lock(&philo[i].eating_mtx);
                time = get_time() - philo[i].last_meal;
                if (time > philo[i].data->t2die)
                {
                        pthread_mutex_unlock(&philo[i].eating_mtx);
                        break;
                }
                pthread_mutex_unlock(&philo[i].eating_mtx);
                i++;
        }
        if (i < n)
        {
                printmes(&philo[i], "died");
                pthread_mutex_lock(&philo[i].data->mtx);
                philo[i].data->someone_dead = 1;
                pthread_mutex_unlock(&philo[i].data->mtx);
        }
}

int     someone_is_dead(t_data *data)
{
        int     someone_dead;

        someone_dead = 0;
        pthread_mutex_lock(&data->mtx);
        if (data->someone_dead == 1)
                someone_dead = 1;
        pthread_mutex_unlock(&data->mtx);
        return (someone_dead);
}

void    *monitor(void *arg)
{
        t_table *table;

        table = (t_table *)arg;
        while (1)
        {
                check_death_time(table->philo, table->data.n_philos);
                if (someone_is_dead(&table->data))
                        break;
        }
        return (NULL);
}
