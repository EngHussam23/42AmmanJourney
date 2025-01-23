int     calc_length(char *src);

char    *ft_strcpy(char *dest, char *src);

int     calc_length(char *src)
{
        int     i;
        int     count;

        i = 0;
        count = 0;
        while (src[i] != '\0')
        {       
                i++;
        }
        count = i;
        i = 0;
        return (count);
}

char    *ft_strcpy(char *dest, char *src)
{
        int     i;
        int     src_count;
        int     dest_count;

        i = 0;
        src_count = calc_length(src);
        dest_count = calc_length(dest);
        if (dest_count >= src_count)
        {
                *dest = *src;
                while (dest_count >= src_count)
                {
                        *dest += '\0';
                        src_count++;
                }
                return (dest);
        }
        else
                while (i <= dest_count)
                {       

                        i++;
                }

}
