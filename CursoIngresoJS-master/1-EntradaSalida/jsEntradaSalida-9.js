/*Debemos lograr tomar el importe por ID ,
transformarlo a entero (parseInt), luego
mostrar el importe con un aumento del 10 %
en el cuadro de texto "RESULTADO".*/
function MostrarAumento()
{
    document.getElementById("resultado").value = parseInt(document.getElementById("sueldo").value)*1.1;
	
}
