#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void retardo(unsigned long int);
void mostrar(unsigned char);
int fvelocidad(unsigned long int);
void auto_fantastico(unsigned long int);
void carrera(unsigned long int);
void choque(unsigned long int);
void bateriaDescargandose(unsigned long int);
void chocaLos5(unsigned long int);

int main()
{
    char contrasenia[] = {'a', 'b', 'c', '1', '0'};
    char contra[20];
    char pw[6];
    int v = 0;
    int contador = 0, intentos = 3;

    while (intentos != 0)
    {
        printf("Ingrese su contrasenia: ");
        for (int i = 0; i < 5; i++)
        {
            v = getch();
            pw[i] = v;
            printf("*");
        }
        pw[5] = '\0';

        if (strcmp(pw, "abc10") != 0)
        {
            contador++;
            intentos--;
            system("cls");
            printf("\nContrasenia incorrecta, le quedan %d intentos\n", intentos);
        }
        else
        {
            intentos = 0;
        }
    }

    if (contador < 3)
    {
        system("cls");
        printf("Bienvenido al sistema\n");
    }
    else
    {
        printf("\nPassword no valida\n");
        
    }

    int opcion = 0;
    unsigned long int velocidadAux = 145000000;
    unsigned long int velocidad = velocidadAux;

    do
    {
        if (contador < 3)
        {
            printf("\n(1) Autos fantastico\n");
            printf("(2) La carrera\n");
            printf("(3) El choque\n");
            printf("(4) Bateria descargandose\n");
            printf("(5) Choca los 5\n");
            printf("(6) Salir\n");

            printf("\nIngrese la opcion que desee visualizar: ");
            scanf("%d", &opcion);
            while (opcion < 1 || opcion > 6)
            {
                printf("Valor erroneo, ingrese nuevamente: ");
                scanf("%d", &opcion);
            }

            switch (opcion)
            {
            case 1:
                system("cls");
                auto_fantastico(velocidad);
                opcion = 0;
                velocidad = velocidadAux;
                break;
            case 2:
                system("cls");
                carrera(velocidad);
                opcion = 0;
                velocidad = velocidadAux;
                break;
            case 3:
                system("cls");
                choque(velocidad);
                opcion = 0;
                velocidad = velocidadAux;
                break;
            case 4:
                system("cls");
                bateriaDescargandose(velocidad);
                opcion = 0;
                velocidad = velocidadAux;
                break;
            case 5:
                system("cls");
                chocaLos5(velocidad);
                opcion = 0;
                velocidad = velocidadAux;
                break;
            case 6:
                system("cls");
                printf("Sistema apagado\n");
                break;
            default:
                system("cls");
                printf("No existe secuencia para ese numero\n");
                opcion = 0;
            }
        }
    } while (opcion != 6);

    return 0;
}

void retardo(unsigned long int a)
{
    while (a)
        a--;
}

void mostrar(unsigned char dato)
{
    for (unsigned char mascara = 128; mascara > 0; mascara >>= 1)
    {
        if (dato & mascara)
        {
            printf("*");
        }
        else
        {
            printf("_");
        }
    }
}

int fvelocidad(unsigned long int velocidad)
{
    if ((velocidad - 4800000) > 9600000)
    {
        if (GetAsyncKeyState(VK_UP) & 0x0001)
        {
            velocidad -= 4800000;
        }
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x0001)
    {
        velocidad += 4800000;
    }
    return velocidad;
}

void auto_fantastico(unsigned long int velocidad)
{
    unsigned int dato;
    while (1)
    {
        dato = 0x80;
        for (int t = 0; t < 8; t++)
        {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(dato);
            retardo(velocidad);
            system("cls");
            dato = dato >> 1;
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
        dato = 0x01;
        for (int i = 0; i < 6; i++)
        {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            dato = dato << 1;
            mostrar(dato);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
    }
}

void carrera(unsigned long int velocidad)
{
    unsigned char tabla[] = {
        0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x88, 0x48, 0x24, 0x14, 0xA, 0x6, 0x3, 0x1};

    while (1)
    {
        for (int i = 0; i < 16; ++i)
        {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
    }
}

void choque(unsigned long int velocidad)
{
    unsigned char tabla[] = {
        0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42};

    while (1)
    {
        for (int i = 0; i < 7; ++i)
        {
            printf("Presione ESC para volver al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
    }
}

void bateriaDescargandose(unsigned long int velocidad)
{
    unsigned int dato = 0xFF;
    while (1)
    {
        for (int i = 0; i < 9; ++i)
        {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(dato);
            dato <<= 1;
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
        dato = 0xFF;
    }
}

void chocaLos5(unsigned long int velocidad)
{
    unsigned char tabla[] = {
        0x0, 0x81, 0xC3, 0xE7, 0xFF, 0xE7, 0xC3, 0x81};
    while (1)
    {
        for (int i = 0; i < 8; i++)
        {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            {
                return;
            }
        }
    }
}

