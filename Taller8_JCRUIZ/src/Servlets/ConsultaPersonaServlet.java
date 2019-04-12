package Servlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

@WebServlet("/Servlets/consultaPersona")
public class ConsultaPersonaServlet extends HttpServlet{
//1: obtener parametros
//2: hacer la consulta en PSQL
//3: imprimir resultado en el HTML
	public void doGet(HttpServletRequest request,
	HttpServletResponse response)
	throws ServletException, IOException
	{
		/*Debe conectarse  la base de datos y extraer la lista
		 *  de los cursos que ha tomado el estudiante y retornar un HTML.
		 *  Si el estudiante no se encuentra, retornar un mensaje
		 */
		
		//El parametro es el name del input
		String nametype = request.getParameter("nombre");
		
		
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		
		out.println("<HEAD><TITLE> Query Result</TITLE></HEAD>");
		out.println("<BODY>");
		//PRIMERO POR HACER
		//2: HACER CONSULTA
		//3: TOMAR RESULTADOS EN L CONSULTA DE DATOS E IMPRIMIR EN EL HTML
		
		//String number = request.getParameter("nombre");
		
		//CAMBIAR NUMERO DE OLUMNAS A NUMERO DE PARAMETROS?
		out.println("<table BORDER COLS=4>");
		out.println(" <tr> <td>Nombres</td> <td>Apellidos </td> <td>nombre curso</td> <td> cod curso </td> </tr>");
		
		try (Connection conexion = DriverManager.getConnection("jdbc:postgresql://localhost:5432/Apps_JCRuiz", "postgres","postgres")){
			Statement statement = conexion.createStatement();
			// Como accedo a los atributos? Tal cual como están en la consulta
			String atributos = "A.nombres, A.apellidos, curso.nombre, curso.curso_cod";
			String relacion = "curso join (select *" + 
					" from estCursos join estudiante" + 
					" on estudiante.id = estCursos.estID) as A" + 
					" on curso.curso_cod = A.curso_cod";
			String condicion = "A.nombres = '" + nametype + "' ;";
			ResultSet resultSet = statement.executeQuery("select "+ atributos + " from " + relacion + " where  " + condicion);
			
			//Consulta celda por celda de la consulta extraida de SQL
			while (resultSet.next()) {
                System.out.printf("%-30.30s  %-30.30s  %-30.30s%n", resultSet.getString("nombres"), resultSet.getString("apellidos"), resultSet.getString("nombre"), resultSet.getString("curso_cod"));
                out.println("<tr> <td>" + resultSet.getString("nombres") + "</td>" +
        				"<td>" + resultSet.getString("apellidos") + "</td>" +
        				"<td>" + resultSet.getString("nombre") + "</td>"+
        				"<td>" + resultSet.getString("curso_cod") + "</td>" + "</tr>");
                
            }
			
			
		} catch (SQLException e) {
			System.out.println("Conexion fallida");
			e.printStackTrace();
		}
		
		
		//
		
		/**if(persontype.equals("estudiante")) {
			ID = 8888;
			nombre = "Juan";
			depto = "MACC";
		}
		else {
			ID = 2222;
			nombre = "Renato";
			depto = "MACC";
		}
		out.println("<tr> <td>" + ID + "</td>" +
				"<td>" + nombre + "</td>" +
				"<td>" + depto + "</td></tr>");
			*/
		out.println("</table>");
		out.println("</BODY>");
		out.close();
	}
}