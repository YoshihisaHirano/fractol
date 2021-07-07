#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;
	size_t		str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	if (str_len - start <= len)
		len = str_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
