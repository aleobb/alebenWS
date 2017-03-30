function Mostrar()
{
//tomo la edad  
var edad = parseInt(document.getElementById("edad").value);
var state = document.getElementById("estadoCivil").value;
if(edad < 18 && state != "Soltero")
	{
        alert("Es muy pequeño para NO ser soltero.");
    }
else
    {
        //alert("Todo ok fierita!");
    }

}//FIN DE LA FUNCIÓN