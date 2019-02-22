package proyect1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class EjemploConexion_Taller4 {
	public static void main(String[] args) {
		// Intenta establecer conexion
		System.out.println("Estableciendo conexion...");
		try(Connection conexion = DriverManager.getConnection("jdbc:postgresql://localhost:5432/diap2db","postgres","postgres")){
			System.out.println("Conexion con la base de datos establecida (PostgreSQL)");
			Statement statement = conexion.createStatement();
			
			///1.b consulta parametrizada
			//Ejemplo 1 (aquí hay un parametro que "ingresa" el usuario)
			//String est_cod = "8888";
			//NOTA: NO SALE EL REGISTRO CON curso_cod = 2 y estID = 3333
			
			//1.c consulta parametrizada con inyeccion retorna TODOS LOS CURSOS Y NOTAS DE TODOS LOS ESTUDIANTES
			String est_cod = "8888' or 'A'='A";
			ResultSet resultSet = statement.executeQuery("select nombre, estCursos.curso_cod, nota"
					+ " from public.curso join estCursos"
					+ " on curso.curso_cod = estCursos.curso_cod"
					+ " where estID ='"+ est_cod +"';");
			
			System.out.println("Imprimiendo resultados...");
			System.out.printf("%-30.30s %-30.30s %-30.30s%n","Nombre_curso","curso_cod","nota");
			while(resultSet.next()) {
				System.out.printf("%-30.30s  %-30.30s %-30.30s%n", resultSet.getString("nombre"),resultSet.getString("curso_cod"), resultSet.getString("nota"));
			}
			System.out.println("-------------------------------------------");
			System.out.println();
			System.out.println("CODIGO CORREGIDO");
			
			//1.d consulta parametrizada - instruccion preparada
			System.out.println("Consultando la base de datos...");
			PreparedStatement prepStatement = 
					conexion.prepareStatement("select nombre, estCursos.curso_cod,nota"
					+ " from public.curso join estCursos"
					+ " on curso.curso_cod = estCursos.curso_cod"
					+ " where cast(estID as varchar(8)) = ? ");
			est_cod = "8888";
			//est_cod = "cast('8888' as int) or 'A'='A ";
			prepStatement.setString(1,est_cod);
			resultSet = prepStatement.executeQuery();
			
			System.out.println("Imprimiendo resultados...");
			System.out.printf("%-30.30s %-30.30s %-30.30s%n","Nombre_curso","curso_cod","nota");
			while(resultSet.next()) {
				System.out.printf("%-30.30s  %-30.30s %-30.30s%n", resultSet.getString("nombre"),resultSet.getString("curso_cod"), resultSet.getString("nota"));
			}
			
			conexion.close();
		}
		catch(SQLException e) {
			System.out.println("Conexion fallida");
			e.printStackTrace();
		};
	}

}
