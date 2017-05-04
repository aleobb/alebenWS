/*Debemos lograr tomar un nombre con 'prompt' 
y luego mostrarlo por 'alert' al presionar el botón  'MOSTRAR'*/
function Prompt()
{

var nota;
var sexo;
var notasTotales = 0;
var notaMasBaja;
var cantVarones = 0;

for (var i=1;i<101;i++) 
    { nota = parseInt(prompt("Ingrese la nota para el alumno nro: " + i));
      while ( isNaN(nota) || nota < 0 || nota > 10  )
            {  nota = parseInt(prompt("El dato ingresado es inválido!! Reingrese la nota para el alumno nro: " + i));  }
      sexo = prompt("Ingrese el sexo del alumno nro: " + i).toLowerCase();
      while ( sexo != "f" && sexo != "m" )
            {  sexo = prompt("El dato ingresado es inválido!! Reingrese el sexo del alumno nro: " + i).toLowerCase();  }

      notasTotales = notasTotales + nota;
      
      if ( nota<notaMasBaja || i==1 )
        { notaMasBaja=nota }

      if ( sexo=="m" && nota >= 6 )
        { cantVarones = cantVarones + 1 }

    }

alert ("El promedio de notas totales es: " + (notasTotales/100) );
alert ("La nota mas baja es: " + notaMasBaja);
alert ("La cantidad de varones cuya nota es mayor o igual a 6: " + cantVarones);

}




function Id()
{

alert("Id");
}

