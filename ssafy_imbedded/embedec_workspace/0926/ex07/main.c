//#define RELEASE
#define DEBUG

#ifdef RELEASE
int main() {
	printf(" hifaker");
	return 0;
}
#endif // RELEASE

#ifdef DEBUG
int main() {
	printf("BBQ");
	return 0;
}
#endif // DEBUG
