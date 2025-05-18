<img src="SampleProject/Thumbnail/Thumbnail.png" /> 

### The ultimate toolkit for using Haxe in Godot. 

# Building

| #   | What to do                                           | What to write                            |
| --- | ---------------------------------------------------- | ---------------------------------------- |
| 1   | Download the source code for [godot-cpp](https://github.com/godotengine/godot-cpp) (choose the branch for your version of Godot) and place it in `CppCode/godot-cpp`.     | <pre>cd &lt;HAXExGODOT&gt;/CppCode<br>git clone -b 4.4 https://github.com/godotengine/godot-cpp.git</pre>   |
| 2   | Install [Python 3](https://www.python.org/)           | <pre>https://www.python.org/</pre>                                     |
| 3   | Install `scons` if you don't have it already.         | <pre>python -m pip install scons</pre>                                 |
| 4   | Run `scons` in `CppCode/godot-cpp`                    | <pre>cd &lt;HAXExGODOT&gt;/CppCode/godot-cpp<br>python -m SCons</pre>  |
| 5   | Run `scons` in `CppCode`                              | <pre>cd &lt;HAXExGODOT&gt;/CppCode<br>python -m SCons</pre>            |
