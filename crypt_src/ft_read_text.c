#include "ft_crypt_operations.h"

unsigned char	*take_crypt_text_from_output(int fd)
{
	unsigned char	*need_to_hash;
	unsigned char	*tmp_buffer;
	unsigned char	*ptr_to_free;

	need_to_hash = ft_memalloc(1);
	tmp_buffer = ft_memalloc(BUFFER_SIZE);
	while (read(fd, tmp_buffer, BUFFER_SIZE - 1))
	{
		ptr_to_free = need_to_hash;
		need_to_hash = ft_strjoin_unsigned(need_to_hash, tmp_buffer);
		free(ptr_to_free);
		ft_memset(tmp_buffer, 0, BUFFER_SIZE);
	}
	free(tmp_buffer);
	if (fd)
		close(fd);
	return (need_to_hash);
}

unsigned char	*ft_strjoin_unsigned(unsigned char const *s1,
									unsigned char const *s2)
{
	int		i;
	unsigned char	*p;

	i = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	p = (unsigned char*)malloc(ft_strlen_unsigned(s1) + ft_strlen_unsigned(s2) + 1);
	if (p == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		p[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		p[i] = *s2;
		i++;
		s2++;
	}
	p[i] = '\0';
	return (p);
}

size_t			ft_strlen_unsigned(const unsigned char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}