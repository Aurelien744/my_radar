/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** Day04
*/

long long error_gestion(long long number)
{
    if (number > 2147483647)
        return (0);
    if (number < -2147483648)
        return (0);
    else {
        return (number);
    }
}

int is_nega(char const *str)
{
    int minus_nb = 2;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            minus_nb = minus_nb + 1;
    }
    return (minus_nb);
}

int long_to_int(long long number, char const *str)
{
    int sign = 0;

    sign = is_nega(str);
    number = number / 10;
    if (sign % 2 != 0)
        number = number * (-1);
    number = error_gestion(number);
    return (number);
}

int nb_e_size(int size, int *actual_nb, char const *str, int i)
{
    if (str[i] >= '0' && str[i] <= '9') {
        *actual_nb = str[i] - 48;
        size++;
    }
    return (size);
}

int my_getnbr(char const *str)
{
    long long number = 0;
    int actual_nb = 0;
    int real_number = 0;
    int size = 0;

    if (str[0] >= 'a' && str[0] <= 'z')
        return (84);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+')
            continue;
        size = nb_e_size(size, &actual_nb, str, i);
        if (size > 10)
            return (0);
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '-'))
            break;
        number = (number + actual_nb) * 10;
    }
    real_number = long_to_int(number, str);
    return (real_number);
}
