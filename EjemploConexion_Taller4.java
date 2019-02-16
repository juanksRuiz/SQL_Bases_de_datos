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
		try(Connection conexion = DriverManager.getConnection("jdbc:postgresql://localgost:5432/diap2_db","postgres","postgres")){
			System.out.println("Conexion con la base de datos establecida (PostgreSQL)");
			Statement statement = conexion.createStatement();
			
			//1.b consulta parametrizada
			//Ejemplo 1 (aquí hay un parametro que "ingresa" el usuario)
			int est_cod = 8888;
			ResultSet resultSet = statement.executeQuery("select nombre,curso_cod,nota "
					+ " from public.curso join estCursos "
					+ " on curso.curso_cod = estCursos.curso_cod "
					+ "where estID =2"+est_cod+"';");
					
		}
		catch(SQLException e) {
			System.out.println("Conexion fallida");
			e.printStackTrace();
		};
	}

}
