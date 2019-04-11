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

@WebServlet("/testServlet/consultaPersona")
public class ConsultaPersonaServlet extends HttpServlet{

	public void doGet(HttpServletRequest request,
	HttpServletResponse response)
	throws ServletException, IOException
	{
		/*Debe conectarse  la base de datos y extraer la lista
		 *  de los cursos que ha tomado el estudiante y retornar un HTML.
		 *  Si el estudiante no se encuentra, retornar un mensaje
		 */
		
		try (Connection conexion = DriverManager.getConnection("jdbc:postgresql://localhost:5432/taller4_base1.sql", "postgres","postgres")){
			Statement statement = conexion.createStatement();
			// Como accedo a los atributos? Tal cual?
			String atributos = "A.nombres, A.apellidos, curso.nombre, A.curso_cod";
			String relacion = "(curso) join" + 
					" (select nombres, apellidos, curso_cod from estCursos join estudiante" + 
					" on estCursos.estId = estudiante.id) where estudiante.id = '5555' as A";
			String condicion = "curso.curso_cod = A.curso_cod";
			ResultSet resultset = statement.executeQuery("select "+ atributos + " from " + relacion + " on " + condicion);
			
			
		} catch (SQLException e) {
			System.out.println("Conexion fallida");
			e.printStackTrace();
		}
		//--------
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		
		out.println("<HEAD><TITLE> Query Result</TITLE></HEAD>");
		out.println("<BODY>");
		String persontype = request.getParameter("tipoPersona");
		//String number = request.getParameter("nombre");
		
		//CAMBIAR NUMERO DE OLUMNAS A NUMERO DE PARAMETROS?
		out.println("<table BORDER COLS=4>");
		out.println(" <tr> <td>ID</td> <td>Nombre: </td> <td>Departamento</td> </tr>");
		int ID;
		String nombre;
		String depto;
		if(persontype.equals("estudiante")) {
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
			
		out.println("</table>");
		out.println("</BODY>");
		out.close();
	}
}