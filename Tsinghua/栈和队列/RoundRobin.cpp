RoundRobin{
	Queue Q(clients);
	while(!ServiceClosed())
	{
		e = Q.dequeue();
		serve(e);
		Q.enqueue(e);
	}
} 
