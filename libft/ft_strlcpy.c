#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	if (!src && !dst)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size);
		dst[size - 1] = '\0';
	}	
	return (src_len);
}
