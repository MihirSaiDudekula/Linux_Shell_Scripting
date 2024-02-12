BEGIN{
	print "Removing Duplicated lines"
}
{
	line[++no]=$0
	}
	END{
		for(i=1;i<=no;i++)
		{
			flag=1
			}
		}
