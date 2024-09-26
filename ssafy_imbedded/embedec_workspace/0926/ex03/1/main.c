#define DEBUG

#ifdef  DEBUG
#define RELEASE
#endif //  DEBUG

#ifdef RELEASE
int main() {
	int a = 1000;
	return 0;
}
#endif // RELEASE

#undef ABC
#ifdef ABC
int main() {
	int a = 2000;
	return 0;
}
#endif // ABC

