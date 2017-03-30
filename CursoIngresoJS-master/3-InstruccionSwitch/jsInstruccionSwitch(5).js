function Mostrar()
{
var hour = parseInt(document.getElementById("hora").value);

switch (hour)
    {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        alert ("Es de mañana");
        break;
    default:
        alert ("NO es de mañana!!");
    }
	



}//FIN DE LA FUNCIÓN