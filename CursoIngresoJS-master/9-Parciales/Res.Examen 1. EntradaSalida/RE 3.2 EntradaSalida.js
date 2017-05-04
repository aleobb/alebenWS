/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{


}

function Id()
{

var p1 = parseInt(document.getElementById("Id1").value);
var p2 = parseInt(document.getElementById("Id2").value);
var p3 = parseInt(document.getElementById("Id3").value);

var suma = p1+p2+p3;

if (isNaN(suma) || p1<=0  || p2<=0  || p3<=0)
    {alert ("Los datos ingresados son inválidos!! Verifique los datos y corríjalos antes de volver a ejecutar la instruccion.");}
else
    { alert("La suma es: " + suma + "  El promedio es: " + (suma/3) ); }

}

