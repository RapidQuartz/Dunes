# include "../../FdF.h"

char	*read_map(int fd)
{
	char	*raw;
	char	*out;

	raw = NULL;
	out = NULL;
	while ((!raw && !out) || (raw && out))
	{
		raw = get_next_line(fd);
		if (!out)
			out = ft_strdup(raw);
		else if (out && raw)
			out = ft_strjoin(out, raw);
	}
	return (out);
}