#include <stdlib.h>

int	my_atoi(const char *str, char *status)
{
  int	nb;
  int	idx;
  int	neg;

  if (str == NULL)
    return (0);
  idx = 0;
  neg = 0;
  *status = 0;
  if (str[0] == '-')
    {
      idx = 1;
      neg = 1;
    }
  nb = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] < '0' || str[idx] > '9')
	*status = 1;
      nb = (nb * 10) + (str[idx] - '0');
      idx += 1;
    }
  if (neg == 1)
    nb = nb * -1;
  return (nb);
}
