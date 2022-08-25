#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Pedir número do cartão ao usuário
int main(void)
{
    long credit;
    do
    {
        credit= get_long("Número do Cartão: ");
    }
    while(credit < 0);

    int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,sum;

    //Determinar a localização dos números a serem multiplicados por 2 e a multiplicação
    c1=((credit % 100)/10)*2;
    c2=((credit % 10000)/1000)*2;
    c3=((credit % 1000000)/100000)*2;
    c4=((credit % 100000000)/10000000)*2;
    c5=((credit % 10000000000)/1000000000)*2;
    c6=((credit % 1000000000000)/100000000000)*2;
    c7=((credit % 100000000000000)/10000000000000)*2;
    c8=((credit % 10000000000000000)/1000000000000000)*2;

    //Somando os resultados da multiplicação, caso tenham dois algarismos some eles
    c1=((c1 % 100)/10 + (c1 % 10));
    c2=((c2 % 100)/10 + (c2 % 10));
    c3=((c3 % 100)/10 + (c3 % 10));
    c4=((c4 % 100)/10 + (c4 % 10));
    c5=((c5 % 100)/10 + (c5 % 10));
    c6=((c6 % 100)/10 + (c6 % 10));
    c7=((c7 % 100)/10 + (c7 % 10));
    c8=((c8 % 100)/10 + (c8 % 10));

    //Determinar os números restantes
    c9=(credit % 10);
    c10=((credit % 1000)/100);
    c11=((credit % 100000)/10000);
    c12=((credit % 10000000)/1000000);
    c13=((credit % 1000000000)/100000000);
    c14=((credit % 100000000000)/10000000000);
    c15=((credit % 10000000000000)/1000000000000);
    c16=((credit % 1000000000000000)/100000000000000);

    //Soma dos números multiplicados por 2 e os que não foram multiplicados
    sum= c1+c2+c3+c4+c5+c6+c7+c8+c9+c10+c11+c12+c13+c14+c15+c16;

    //Se o resultado da soma tiver como último algarismo um número diferente de 0, deve-se determinar como inválido
    if ((sum % 10) != 0)
    {
        printf("%s", "INVALID\n");
        return 0;
    }

    //Identificando a quantidade de dígitos do cartão e a marca
    int qd = 0;
    long visa = credit;
    long amex = credit;
    long mastercard = credit;

    while (credit > 0)
    {
        credit = credit / 10;
        qd++;
    }

    //Identificar cartão VISA
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (qd == 13 || qd == 16))
    {
        printf("%s", "VISA\n");
        return 0;
    }

    //Identificar cartão AMEX
    while (amex >= pow(10,13))
    {
        amex /= pow (10,13);
    }

    if ( (amex == 34 || amex == 37) && qd == 15 )
    {
        printf("%s","AMEX\n");
        return 0;
    }

    //Identificar cartão MASTERCARD
    while ( mastercard >= pow(10,14))
    {
        mastercard /= pow(10,14);
    }
    if ((mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55) && qd == 16)
    {
        printf("%s","MASTERCARD\n");
        return 0;
    }
    else
    printf("%s","INVALID\n");
    return 0;
}
