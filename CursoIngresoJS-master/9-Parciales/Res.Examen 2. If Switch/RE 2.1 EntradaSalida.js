/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{

var dia;

do  {
    dia = prompt("Ingrese un dia de la semana:").toLowerCase();
    switch (dia)
        {
        case "sabado":  
        case "domingo":
            alert ("es un fin de semana");
            break;
        case "lunes":
        case "martes":
        case "miercoles":
        case "jueves":
        case "viernes":
            alert ("a trabajar!!!");
            break;
        default:
            alert ("El dia ingresado es invalido!!");
            dia = 1;
        }
    
    } while (dia == 1);

}





function Id()
{


}

