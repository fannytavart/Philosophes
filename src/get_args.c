#include <string.h>
#include <stdio.h>
#include "my.h"
#include "philo.h"

static char	set_philo(const char *nb_philo, t_info *info)
{
  char		status;

  if (nb_philo == NULL)
    {
      fprintf(stderr, "Number of philosophers not specified.\n");
      return (1);
    }
  if ((info->nb_philo = my_atoi(nb_philo, &status)) < 2
      || status != 0)
    {
      fprintf(stderr, "Incorrect number of philosophers.\n");
      return (1);
    }
  return (0);
}

static void	init_info(t_info *info)
{
  info->nb_philo = 0;
  info->occ = 0;
  info->done = 0;
  info->created = 0;
}

static char	set_occurence(const char *nb_occurence, t_info *info)
{
  char		status;

  if (nb_occurence == NULL)
    {
      fprintf(stderr, "Number of occurence not specified.\n");
      return (1);
    }
  if ((info->occ = my_atoi(nb_occurence, &status)) < 1
      || status != 0)
    {
      fprintf(stderr, "Incorrect number of max eat occurences.\n");
      return (1);
    }
  return (0);
}

char		get_args(int ac, char **av, t_info *info)
{
  unsigned	idx;

  if (ac != 5)
    {
      fprintf(stderr, "Usage: %s -p [NB OF PHILOS] -e [MAX EAT OCCURENCES]\n",
	      av[0]);
      return (1);
    }
  idx = 0;
  init_info(info);
  while (av[idx] != NULL)
    {
      if (strcmp(av[idx], "-p") == 0)
	{
	  if (set_philo(av[idx + 1], info) != 0)
	    return (1);
	}
      else if (strcmp(av[idx], "-e") == 0)
	{
	  if (set_occurence(av[idx + 1], info) != 0)
	    return (1);
	}
      idx += 1;
    }
  return (0);
}
