class Solution {
public:
    string simplifyPath(string path) {
        string result;
        stack<string> tokens;
        size_t pos, end;

        for (pos = 0; pos < path.size(); pos = end + 1) {
            while (pos < path.size() && path[pos] == '/')
                pos++;
            end = path.find("/", pos);

            if (end == string::npos)
                end = path.size();
            tokens.push(path.substr(pos, end - pos));
        }

        while (!tokens.empty()) {
            string name = tokens.top();
            tokens.pop();

            if (name.empty() || name == ".") {
                continue;
            } else if (name == "..") {
                for (int count = 1; count > 0; ) {
                    if (tokens.empty())
                        break;
                    else if (tokens.top() == "..")
                        count++;
                    else if (tokens.top() != ".")
                        count--;
                    tokens.pop();
                }
            } else {
                result = "/" + name + result ;
            }
        }

        return result.empty() ? "/" : result;
    }
};

// v2
class Solution {
public:
    string simplifyPath(string path) {
        string dentry;
        stack<string> stack;
        istringstream iss(path);

        while (getline(iss, dentry, '/')) {
            if (dentry == "." || dentry.empty())
                continue;
            if (dentry == "..") {
                if (!stack.empty())
                    stack.pop();
                continue;
            }
            stack.push(dentry);
        }

        string result;
        while (!stack.empty()) {
            result = "/" + stack.top() + result;
            stack.pop();
        }

        return result.empty() ? "/" : result;
    }
};

