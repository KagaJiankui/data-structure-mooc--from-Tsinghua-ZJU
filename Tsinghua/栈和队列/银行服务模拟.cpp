struct Customer{int window;unsigned int time}; 
void simulate(int nwin,int servTime)
{
	Queue<Customer>* windows = new Queue<Customer>[nwin];
	for(int now=0;now<servTime;now++0
	{
		if(rand()%(1+nwin))
		{
			Customer c;
			c.time = 1+rand()%98;
			c.window = bestWindow(windows,nwin);
			windows[c.window].enqueue(c);
		}
		for(int i=0;i<nwin;i++)
		{
			if(!windows[i].empty())
			{
				if(--windows[i].front().time<=0)
				{
					windows[i].dequeue;
				}
			 } 
		}
	}
	delete []windows;
}
int bestWindow(Queue<Customer> windows[],int nwin)
{
	int minsize=  windows[0].size(),optwin=0;
	for(int i=0;i<nwin;i++)
	{
		if(minsize<windows[i].size())
		{
			minsize = windows[i].size();
			optwin = i;
		}
	}
	return optwin;
 } 
