#include <stdio.h>

int main(void)
{
    // Define las variables para el usuario y contraseña usando arreglos de caracteres.
    char username[50];  
    char password[50];
    char correct_password[] = "admin123";
    // Define variables para el conteo de caracteres sin espacios, intentos, y validaciones.
    int i;
    int non_space;
    int attempts = 0;
    int has_number;
    int is_same;

    // Validacion de usuario: debe tener al menos 5 caracteres no espaciales
    do
    {
        printf("Enter username (minimum 5 characters): ");
        scanf(" %49[^\n]", username);

        non_space = 0;

        //Recorre cada caracter del usuario para verificar que no haya ningun espacio.

        for (i = 0; username[i] != '\0'; i++)
        {
            if (username[i] == ' ')
                continue;

            non_space++;
        }

        //Checa si no hay al menos 5 caracteres no espaciales, si no los hay, se le indica al usuario que el nombre de usuario es invalido y se le vuelve a pedir que ingrese un nombre de usuario.

        if (non_space < 5)
            printf("Invalid username\n");

    } while (non_space < 5);

    // Validacion de contraseña
    while (attempts < 3)
    {
        printf("Enter password: ");
        scanf(" %49[^\n]", password);

        has_number = 0;

        //Recorre cada caracter de la contraseña para verificar si tiene al menos un número
        for (i = 0; password[i] != '\0'; i++)
        {
            if (password[i] >= '0' && password[i] <= '9')
            {
                has_number = 1;
                break;
            }
        }

        // Si no tiene al menos un numero, se le indica al usuario que al menos debe de contener un numero.

        if (!has_number)
        {
            printf("Password must contain at least one number.\n");
            attempts++;
            continue;
        }

        // Compara la contraseña ingresada con la contraseña correcta. Si son iguales, se concede el acceso.

        is_same = 1;

        for (i = 0; correct_password[i] != '\0' || password[i] != '\0'; i++)
        {
            if (password[i] != correct_password[i])
            {
                is_same = 0;
                break;
            }
        }

        // Hace la validacion de la contraseña, si es correcta, se concede el acceso, de lo contrario, se le indica al usuario que la contraseña es incorrecta y se incrementa el conteo de intentos.

        if (is_same)
        {
            printf("Access granted.\n");
            return 0;
        }

    // Si la contraseña es incorrecta, se le indica al usuario que la contraseña es incorrecta y se incrementa el conteo de intentos.


        printf("Incorrect password.\n");
        attempts++;
    }

    printf("Account locked.\n");
    return 0;
}