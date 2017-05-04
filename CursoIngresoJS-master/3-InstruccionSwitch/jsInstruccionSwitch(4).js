function Mostrar()
{
var month = document.getElementById("mes").value;
switch(month)
    {
        case "Febrero":
            alert ("El mes de " + month + " tiene 28 días");
            break;
        case "Abril":
        case "Junio":
        case "Septiembre":
        case "Noviembre":
            alert ("El mes de " + month + " tiene 30 días");
            break;
        default:
            alert ("El mes de " + month + " tiene 31 días");
            break;
    }
}//FIN DE LA FUNCIÓN