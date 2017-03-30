/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{
var mes;
do {
    mes = prompt("Ingrese un mes del año:").toLowerCase();
    switch (mes)
        {
        case "diciembre":  
            alert ("Se vienen las fiestas!!");
            break;
        case "enero":
            alert ("Comienza el año");
            break;
        case "febrero":
        case "marzo":
        case "abril":
        case "mayo":
        case "junio":
        case "julio":
        case "agosto":
        case "septiembre":
        case "octubre":
        case "noviembre":
            alert ("No es Enero ni Diciembre");
            break;
        default:
            alert ("El mes ingresado es invalido!!");
            mes = 1
        }
    } while (mes == 1);
}



function Id()
{


}

