struct profile{
	long id;
	char *name;
	char *aboutme;
	long rep;

};

PROFILE make_profile(long id, long rep, char *name, char *aboutme){
	PROFILE p = malloc(sizeof PROFILE);
	p->id = id;
	p->rep = rep;
	p->name = g_mystrdup(name);
	p->aboutme = g_mystrdup(aboutme);
}

long get_id(PROFILE p){
	if (p) return p->id;
	 return NULL;
}

long get_rep(PROFILE p){
	if (p) return p->rep;
	 return NULL;
}

char* get_name(PROFILE p){
	if (p) return p->name;
	return NULL;
}

char* get_profile(PROFILE p){
	if (p) return p-> aboutme;
	return NULL;
}

void free_profile(PROFILE p){
	if (p) {
		free(p->name);
		free(p->aboutme);
		free(p);
	}
}