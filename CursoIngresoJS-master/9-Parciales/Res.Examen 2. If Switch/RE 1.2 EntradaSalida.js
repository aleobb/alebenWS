/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{

var n1 = parseInt(prompt("Ingrese el 1º numero"));
while (isNaN(n1))
    {n1 = parseInt(prompt("El dato ingresado es inválido!! Reingrese el 1º numero"));}

var n2 = parseInt(prompt("Ingrese el 2º numero"));
while (isNaN(n2))
    {n2 = parseInt(prompt("El dato ingresado es inválido!! Reingrese el 2º numero"));}

var suma = n1 + n2

if (suma>0) 
    { document.write("positivo"); }
else if (suma<0) 
    { document.write("negativo"); }
else
    { document.write("cero"); }


}




function Id()
{

alert("Id");
}

