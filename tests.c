void	*ft_strrchr(const void *s, int c, size_t n)
{ 
    int	i;

    i = 0;
    while (i < n)
    {
        if (s[i] == (char)c)
            return ((void *)s + i);
        i++;
    }
    return (NULL);
}

int	memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);

char	*strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (big[i + j] && (i + j < len) && (j < little_len))
	{
		if (big[i + j] == little[j]
			j++;
		else
			j = 0;
		i++;
	}
	if (j == little_len)
		return ((char *)big + i);
	else
		return (NULL);
}


int	atoi(const char *str)
{
	int	i;
	int	n;
	int	pos;

	i = 0;
	n  = 0;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
		i++;
	if (str[i] == '-')
		pos = -1;
	else
		pos = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i])
	{
		n *= 10;
		n += str[i++] - 48;
	}
	return (n * pos);
}
