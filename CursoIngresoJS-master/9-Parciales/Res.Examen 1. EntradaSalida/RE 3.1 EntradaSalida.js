/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{


}

function Id()
{

var largo = parseInt(document.getElementById("Id1").value);
var ancho = parseInt(document.getElementById("Id2").value);

if (isNaN(largo+ancho) || largo<=0  || ancho<=0)
    {alert ("Los datos ingresados son inválidos!! Verifique los datos y corríjalos antes de volver a ejecutar la instruccion.");}
else
    { alert("La cantidad de metros de alambre que se necesitan son: " + ((largo + ancho) * 2 * 3) ); 

}

