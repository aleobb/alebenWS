function Mostrar()
{
	var contador = 0;
	var sumaNeg = 0;
	var sumaPos = 0;
	var cantPos = 0;
	var cantNeg = 0;
	var cantCeros = 0;
	var cantPares = 0;
	var promedioPos = 0;
	var promedioNeg = 0;
	var seguir;
	var num;

do
{
	contador++;

	num = parseInt(prompt("Ingrese el " + contador + "º numero."));
	while ( isNaN(num) )
		{	num = parseInt(prompt("El dato ingresado es inválido. Ingrese el " + contador + "º numero nuevamente."));  }
	
	if ( (num  % 2) == 0 )  // Puede funcionar con:  cantPares = Math.abs ( ( num + 1 ) % 2 ) + cantPares;
		{	cantPares++;  }
	
	if( num > 0 )
		{	sumaPos = sumaPos + num;
			cantPos++;  } 
	else if ( num < 0 )
		{	sumaNeg = sumaNeg + num;
			cantNeg++; 	}
	else
		{	cantCeros++; }

	seguir = confirm("Desea continuar ingresando valores?");
}while(seguir);

if ( cantPos != 0 )
		{  promedioPos = sumaPos / cantPos ; }

if ( cantNeg != 0 )
		{  promedioNeg = sumaNeg / cantNeg ; }

document.write("Suma de Negativos:     " + sumaNeg + 
		 "</br> Suma de Positivos:     " + sumaPos + 
		 "</br> Cantidad de Positivos: " + cantPos + 
		 "</br> Cantidad de Negativos: " + cantNeg + 
		 "</br> Cantidad de Ceros:     " + cantCeros + 
		 "</br> Cantidad de Pares:     " + cantPares +
		 "</br> Promedio de Positivos: " + promedioPos +
		 "</br> Promedio de Negativos: " + promedioNeg + 
		 "</br> Diferencia Pos-Neg:    " + ( sumaPos + sumaNeg )  );

}//FIN DE LA FUNCIÓN