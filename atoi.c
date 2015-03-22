#include <stdio.h>
int atoi(const char * str)
{
    int value = 0;
    int sign =1 ;
    if(*str == '-')
    {
        sign = -1;
        str ++;
    }
    while(*str)
    {
        value = value * 10 + *str -'0';
        str++;
    }
    return value * sign;
}
int atoi_radix(const char * str)
{
    int value = 0;
    int sign = 1;
    int radix = 10;
    if(*str == '-')
    {
        sign = -1;
        str ++;
    }
    if(*str == '0'&& (*(str+1)=='x'||*(str+1)=='X'))
    {
        radix = 16;
        str += 2;
    }
    else if(*str == '0')
    {
        radix = 8;
        str ++;
    }
    else {
        radix = 10;
    }
    while(*str)
    {
        if(radix == 16)
        {
            if(*str >= '0'&& *str <= '9')
            {
                value = value *radix + (*str-'0');
            }
            else {
                value = value *radix + (*str | 0x20)-'a';
            }
        }
        else{
            value = value * radix + *str - '0';
        }
        str ++;
    }
    return value * sign;
}
int main()
{
    printf("Decimal string Tanslation!/n/n");
    printf("123456=%d\n",atoi("123456"));
    printf("-123456=%d\n",atoi("-123456"));
    printf("-0x121334 = %d\n", atoi_radix("-0x121334"));
    printf("-0123 = %d \n", atoi_radix("-0123"));
    return 0;
}
