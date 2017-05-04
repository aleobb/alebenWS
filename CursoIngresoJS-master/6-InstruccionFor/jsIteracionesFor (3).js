function Mostrar()
{

var cantRepet = parseInt(prompt("ingrese el número de repeticiones"));
while ( isNaN(cantRepet) )
    { cantRepet = parseInt(prompt("El dato ingresado es erroneo!! Reingrese el número de repeticiones valido"));  }

for ( cantRepet ; cantRepet>0 ; cantRepet-- )
    { //console.log (cantRepet + ". Hola UTN FRA") 
      alert("Hola UTN FRA (" + cantRepet +")"); }

}//FIN DE LA FUNCIÓN