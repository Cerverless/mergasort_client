all: ms_client  

ms_client: ms_client.o toyws.o
	$(Q)$(CC) $(CFLAGS) $^ -o $@ -L../lib -lws

run_two_jobs: run_two_jobs.o toyws.o 
	$(Q)$(CC) $(CFLAGS) $^ -o $@ -L../lib -lws 

get_job_status: get_job_status.o toyws.o 
	$(Q)$(CC) $(CFLAGS) $^ -o $@ -L../lib -lws 

clean:
	rm -f msc *.o *.a *.gch #This way is cleaner than your clean
