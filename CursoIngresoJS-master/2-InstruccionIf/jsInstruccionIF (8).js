function Mostrar()
{
//tomo la edad  

	var edad = parseInt(document.getElementById("edad").value);
    var state = document.getElementById("estadoCivil").value;
    if(edad >= 18 && state == "Soltero")
     {
         alert("Es soltero y no es menor.");
     }

}//FIN DE LA FUNCIÓN