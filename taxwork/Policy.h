#ifndef POLICY_H
#define POLICY_H
#include <string>
using namespace std;
class Policy {

private:
	string policyName;
	string impactLevel;

public:
	void implement();

	void revoke();

	void setPolicyName(string name);

	string getPolicyName() const;
};

#endif