<h2><a href="https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1312. Minimum Insertion Steps to Make a String Palindrome</a></h2><h3>Hard</h3><hr><div><p>Given a string <code>s</code>. In one step you can insert any character at any index of the string.</p>

<p>Return <em>the minimum number of steps</em> to make <code>s</code>&nbsp;palindrome.</p>

<p>A&nbsp;<b>Palindrome String</b>&nbsp;is one that reads the same backward as well as forward.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "zzazz"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string "zzazz" is already palindrome we do not need any insertions.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "mbadm"
<strong>Output:</strong> 2
<strong>Explanation:</strong> String can be "mbdadbm" or "mdbabdm".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> 5
<strong>Explanation:</strong> Inserting 5 characters the string becomes "leetcodocteel".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
</div>