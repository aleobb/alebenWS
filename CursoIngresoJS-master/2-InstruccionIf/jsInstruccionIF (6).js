function Mostrar()
{
//tomo la edad  
var edad = parseInt(document.getElementById("edad").value);
if(edad<13)
    {
        alert("Es niño");
    }
else if(edad>=18)
    {
        alert("Es adulto");
    }
else
    {
        alert("Es adolescente");
    }


}//FIN DE LA FUNCIÓN