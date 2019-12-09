int     ft_bitcmp(int a, int b)
{
    int i = 32;
    while (i >= 0)
    {
        if ((1 & a >> i) != (1 & b >> 1))
            return (0);
        i--;
    }
    return (1);
}

int     main()
{
    int i = -2147483648;
    while (i < 214748364)
    {
        if (ft_bitcmp(i, 0))
            i = i + 0;
        i++;
    }
    return (0);
}