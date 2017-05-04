/*Debemos lograr tomar nombre y edad por ID y mostrarlos concatenados 
ej.: "Usted se llama José y tiene 66 años" 	*/
function Mostar()
{	
	var name;
    var edad;
    name = document.getElementById("elNombre").value;
    edad = document.getElementById("laEdad").value;
    alert("Usted se llama " + name + " y tiene " + edad + " años");
}

