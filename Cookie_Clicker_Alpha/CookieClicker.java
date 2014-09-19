/**
 * 	@author Frank
 *	Website: http://delphi.zijinshi.org
 *	Email: frank@zijinshi.org
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class CookieClicker
{

	double c;
	double f;
	double x;
	
	/**
	 * @param args
	 */
	public static void main( String[] args )
	{
		(new CookieClicker()).processCookieClicker( );

	}
	
	final static String inputFileName = "B-large.in";
	final static String outputFileName = inputFileName.replaceAll( "in", "out" );
	final static double ACCURCY = 0.0000000001;
	
	public void processCookieClicker() {		
		int count;
		FileReader fr = null;
		BufferedReader br = null;

		FileWriter fw = null;
		BufferedWriter bw = null;
		
		// read the input file
		try {
			fr = new FileReader(inputFileName);
			br = new BufferedReader(fr);
			
			fw = new FileWriter(outputFileName);
			bw = new BufferedWriter(fw); 
			
			String myreadline; 

			while (br.ready()) {
				myreadline = br.readLine().trim( );
				count = Integer.parseInt( myreadline );
				for( int i = 0; i < count; i ++ )
				{
					String[] values1 = new String[3];
					values1 = getCookieInfo(br);
					double outputString = getResultString(values1);
					bw.write( "Case #" + (i + 1) + ": " + String.format( "%.7f", outputString ) + "\n" );
				}
				break;
			}
			
			bw.close( );
			fw.close( );
			
			br.close();
			fr.close();

		} catch (FileNotFoundException e) {
			System.out.println(inputFileName + " not found.");
		} catch (IOException e) {
			System.out.println("Error occurs when reading file "
					+ inputFileName);
		}
	}
	
	public double getResultString( String[] result )
	{
		c = Double.parseDouble( result[0] );
		f = Double.parseDouble( result[1] );
		x = Double.parseDouble( result[2] );
		double timesDouble =  x / c - 1 - 2 / f;
		timesDouble = timesDouble >=0 ? ( timesDouble + ACCURCY ): ( timesDouble - ACCURCY );
		int times = (int)Math.floor( timesDouble );		
		double time = 0.0;
		for( int i = 0; i <= times; i ++ )
		{
			time += c / ( 2 + i * f  );
		}
		times = ( times + 1 ) >= 0 ? ( times + 1) : 0; 
		time +=  x / ( 2 + times * f );
		return time;
	}
	
	private String[] getCookieInfo( BufferedReader br )
	{
		String[] values = new String[0];
		String myreadline;
		try
		{
			myreadline = br.readLine().trim( );
			values = myreadline.split(" ");
			assert (values.length == 3);	
		}
		catch ( IOException e )
		{
			e.printStackTrace();
		}
		return values;
	}
}
