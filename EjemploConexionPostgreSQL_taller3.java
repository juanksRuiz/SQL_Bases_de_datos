package proyect1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class EjemploConexionPostgreSQL_taller3 {
    public static void main(String[] args) {
    	
    	//Intenta establecer conexi�n
    	System.out.println("Estableciendo conexi�n...");
        try (Connection conexion = DriverManager.getConnection("jdbc:postgresql://localhost:5432/diap2db", "postgres", "postgres")) {
 
            
            System.out.println("Conexion con la base de datos establecida (PostgreSQL)");
            Statement statement = conexion.createStatement();
            
            
            
          //Ejemplo inserci�n
           // System.out.println("Consultando la base de datos...");
            //statement.executeUpdate("insert into curso values ('005', 'probabilidad', 'MACC', 3);");
            
          //Ejemplo consulta
            System.out.println("Consultando la base de datos...");
            ResultSet resultSet = statement.executeQuery("select nombre, nombre_unid, creditos from public.curso where nombre_unid = 'MACC';");
            
            System.out.println("Imprimiendo resultados...");
            System.out.printf("%-30.30s  %-30.30s %-30.30s%n", "Nombre", "Unidad", "# cr�ditos");
            int totCreditos = 0;
            while (resultSet.next()) {
                System.out.printf("%-30.30s  %-30.30s  %-30.30s%n", resultSet.getString("nombre"), resultSet.getString("nombre_unid"), resultSet.getString("creditos"));
                totCreditos += Integer.parseInt(resultSet.getString("creditos"));
            }
            System.out.printf("# cr�ditos totales: %d%n", totCreditos);
            
            
        } catch (SQLException e) {
            System.out.println("Conexi�n fallida");
            e.printStackTrace();
        }
    }

}



 
