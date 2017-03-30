/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{

var importe = parseInt(prompt("Ingrese el importe del producto:"));
while (isNaN(importe) || importe <= 0)
    {importe = parseInt(prompt("El dato ingresado es inválido!! Reingrese el importe del producto:"));}
    
alert("El importe final del producto es: " + (importe * 1.21) );

}

function Id()
{


}

