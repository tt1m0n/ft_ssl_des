#include "ft_crypt_operations.h"

unsigned char	*take_crypt_text_from_output(int fd, t_crypt_info *crypt_info)
{
	unsigned char	*need_to_crypt;
	unsigned char	*tmp_buffer;
	unsigned char	*ptr_to_free;
	unsigned int    ret_len;

	need_to_crypt = ft_memalloc(1);
	tmp_buffer = ft_memalloc(BUFFER_SIZE);
	while ((ret_len = read(fd, (void*)tmp_buffer, BUFFER_SIZE - 1)) > 0)
	{
		ptr_to_free = need_to_crypt;
		need_to_crypt = ft_strjoin_unsigned(need_to_crypt, tmp_buffer);
		free(ptr_to_free);
		ft_memset(tmp_buffer, 0, BUFFER_SIZE);
		crypt_info->data_len += ret_len;
	}
	free(tmp_buffer);
	if (fd)
		close(fd);
	return (need_to_crypt);
}

unsigned char	*ft_strjoin_unsigned(unsigned char const *s1,
									unsigned char const *s2)
{
	int		        i;
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