{split($0, arr, "-")
       if((arr[1]>31) || (arr[1]<1) || (arr[2]>12) || (arr[2]<1))
       {
	       print "invalid"
	       exit 0

	}	       
	else{
		print arr[1]
		if(arr[2]==1)
		{ print "Jan" }
		if(arr[2]==2)
                { print "Feb" }
		if(arr[2]==3)
                { print "March" }
                if(arr[2]==4)
                { print "April" }
                if(arr[2]==5)
                { print "May" }
                if(arr[2]==6)
                { print "Jun" }
                if(arr[2]==1)
                { print "Jan" }
                if(arr[2]==1)
                { print "Jan" }
                if(arr[2]==1)
                { print "Jan" }
                if(arr[2]==1)
                { print "Jan" }
		print arr[3]
	}
}

