import java.util.*;
import java.io.*;
import java.text.*;

class Main {

	void start() throws Exception {
	
		// imprime o nome do campeonato
		System.out.println(readLine(110));

		int teamsCount = Integer.parseInt(readLine(5));

		ArrayList teams = new ArrayList(teamsCount+1);
		Hashtable teamsTable = new Hashtable();
		while(teamsCount--!=0) {
			Team t = new Team();
			t.name = readLine(100);
			teams.add(t);
			teamsTable.put(t.name,t);
		}

		int gamesCount = Integer.parseInt(readLine(5));
		while(gamesCount--!=0) {
			String line = readLine(100);
			int arroba = line.indexOf('@');
			Team t1 = (Team) teamsTable.get(line.substring(0,line.indexOf('#')));
			int goals1 = Integer.parseInt(line.substring(line.indexOf('#')+1,arroba));
			t1.goals += goals1;
			line = line.substring(arroba);
			Team t2 = (Team) teamsTable.get(line.substring(line.indexOf('#')+1));
			int goals2 = Integer.parseInt(line.substring(1,line.indexOf('#')));
			t2.goals += goals2;
			t1.against += goals2;
			t2.against += goals1;

			t1.games++;
			t2.games++;

			if(goals1>goals2) {
				t1.won++;
				t2.lost++;
				t1.points+=3;
			} else if(goals1<goals2) {
				t2.won++;
				t1.lost++;
				t2.points+=3;
			} else {
				t1.draw++;
				t2.draw++;
				t1.points+=1;
				t2.points+=1;
			}

		}

		TreeSet h = new TreeSet(new CompareTeams());
		h.addAll(teams);

		int i=1;
		for(Iterator it = h.iterator();it.hasNext();i++) {
			Team t = (Team) it.next();
			System.out.println(
				i + ") " + t.name + " " + t.points + "p, " + t.games + "g ("
				+ t.won + "-" + t.draw + "-" + t.lost + "), " + (t.goals-t.against) + "gd ("
				+ t.goals + "-" + t.against + ")"
			);
		}

	}

	public static void main(String args[]) throws Exception {
	
	try {
		int caseCount = Integer.parseInt(readLine(5));
		int i = 0;
		while(caseCount--!=0) {
			if(i++!=0) System.out.println();
			new Main().start();
		}
	} catch(Exception ex) {
		while(true) {
		}
	}
	
	}
	
	static String[] split(String s) {
		StringTokenizer st = new StringTokenizer(s, " ");
		String[] tokens = new String[st.countTokens()];
		for (int i = 0; i != tokens.length; i++) {
			tokens[i] = st.nextToken();
		}
		return tokens;
	}

	// le uma linha inteira
	static String readLine(int maxLg) throws IOException {

		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;

		while (lg < maxLg) {
			car = System.in.read();
			if ((car < 0) || (car == '\n')) {
				break;
			}
			lin[lg++] += car;
		}

		if ((car < 0) && (lg == 0)) {
			return (null); // eof
		}

		return (new String(lin, 0, lg));

	}

}

class Team {
	String name;
	int won=0;
	int lost=0;
	int draw=0;
	int games=0;
	int goals=0;
	int against=0;
	int points=0;
}

class CompareTeams implements Comparator {

	public int compare(Object o1,Object o2) {
	
		Team t1 = (Team) o1;
		Team t2 = (Team) o2;
		
		if(t1.points!=t2.points) {
//			System.out.println(t1.name + t2.name + ":pontos");
			return t1.points<t2.points?1:-1;
		}
		
		if(t1.won!=t2.won) {
//			System.out.println(t1.name + t2.name + ":won");
			return t1.won < t2.won ? 1 : -1;
		}
		
		if(t1.goals-t1.against!=t2.goals-t2.against) {
//			System.out.println(t1.name + t2.name + ":+-");
			return t1.goals-t1.against < t2.goals-t2.against ? 1 : -1;
		}
		
		if(t1.goals!=t2.goals) {
//			System.out.println(t1.name + t2.name + ":goals");
			return t1.goals < t2.goals ? 1 : -1;
		}
		
		if(t1.games!=t2.games) {
//			System.out.println(t1.name + t2.name + ":games");
			return t1.games < t2.games ? -1 : 1;
		}
		
//		System.out.println(t1.name + t2.name + ":name");
		//if(!t1.name.equalsIgnoreCase(t2.name)) {
			return t1.name.compareToIgnoreCase(t2.name);
		//} else {
		//	return t1.name.compareTo(t2.name);
		//}
		
	}

}
