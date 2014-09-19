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
import java.util.ArrayList;
import java.util.List;


public class MagicTrick
{
	
	final static String inputFileName = "A-small-attempt1.in";
	final static String outputFileName = "MagicTrick.output";
	/**
	 * @param args
	 */
	public static void main( String[] args )
	{
		(new MagicTrick()).processMagicTrick( );
	}
	
	private String[] getEachTrickInfo( BufferedReader br )
	{
		String[] values = new String[0];
		String myreadline;
		try
		{
			myreadline = br.readLine().trim( );
			int ret = Integer.parseInt( myreadline ) - 1;
			for( int i = 0; i < 4; i ++ )
			{
				myreadline = br.readLine().trim( );
				if( i != ret)
				{
					continue;
				}
				values = myreadline.split(" ");
				assert (values.length == 4);				
			}
		}
		catch ( IOException e )
		{
			e.printStackTrace();
		}
		return values;
	}
	
	private List<String> processTrickPair( String[] values1, String[] values2)
	{
		List<String> ret = new ArrayList<String>();
		for( int i = 0; i < values1.length; i ++ )
		{
			for( int j = 0; j < values2.length; j ++ )
			{
				if( values1[i].equals( values2[j]))
				{
					ret.add( values1[i] );
				}
			}
		}
		return ret;
	}
	
	public String getResultString( List<String> result )
	{
		String ret = "";
		if(result.size( ) == 1) 
		{
			return result.get( 0 );
		}else
		if( result.size( ) >= 2 )
		{
			return "Bad magician!";
		}else
		if( result.size( ) == 0 )
		{
			return "Volunteer cheated!";
		}
		return ret;
	}
	
	public void processMagicTrick() {		
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
					String[] values1 = new String[4];
					String[] values2 = new String[4];
					values1 = getEachTrickInfo(br);
					values2 = getEachTrickInfo(br);
					List<String> proResult = processTrickPair( values1, values2 );
					String outputString = getResultString(proResult);
					bw.write( "Case #" + (i + 1) + ": " + outputString + "\n" );
				}
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

}
