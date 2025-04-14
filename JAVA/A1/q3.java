import java.io.*;
import java.util.*;
class q3
{
	public static void main(String args[])
	{
		Set<String>flavors=new HashSet<>();
		Map<String,Double> prices=new HashMap<>();

		Scanner sc=new Scanner(System.in);

		System.out.println("enter the number of icecream flavor: ");
		int n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.println("enter the icecream flavor"+(i+1)+":");
			String flavor=sc.next();
			flavors.add(flavor);
		}
		System.out.println(flavors);

		System.out.println("enter the prices of flavors: ");
		for(String flavor:flavors)
		{
			double price=sc.nextDouble();
			prices.put(flavor,price);
		}
		while(true)
		{
			System.out.println("\nmenu");
			System.out.println("1.search for flavor: ");
			System.out.println("2.sort all flavors");
			System.out.println("3.exit\n enter the choice: ");
			int choice=sc.nextInt();
			switch(choice)
			{
				case 1:
					System.out.println("\n the flavor to be search: ");
					String flavorToSearch=sc.next();
					if(flavors.contains(flavorToSearch))
					{
						System.out.println("flavor found");
					}
					else
					{
						System.out.println("flavor not found");
					}
					break;
				case 2:
					 System.out.println("sorting flavor");
					 List<String>sortedFlavors=new ArrayList<>(flavors);
					 Collections.sort(sortedFlavors);
					 System.out.println("sorted flavor: "+sortedFlavors);
					 break;
				case 3:sc.close();
				       break;
default:
				       System.out.println("invalid choice");
			}
		}
	}
}
