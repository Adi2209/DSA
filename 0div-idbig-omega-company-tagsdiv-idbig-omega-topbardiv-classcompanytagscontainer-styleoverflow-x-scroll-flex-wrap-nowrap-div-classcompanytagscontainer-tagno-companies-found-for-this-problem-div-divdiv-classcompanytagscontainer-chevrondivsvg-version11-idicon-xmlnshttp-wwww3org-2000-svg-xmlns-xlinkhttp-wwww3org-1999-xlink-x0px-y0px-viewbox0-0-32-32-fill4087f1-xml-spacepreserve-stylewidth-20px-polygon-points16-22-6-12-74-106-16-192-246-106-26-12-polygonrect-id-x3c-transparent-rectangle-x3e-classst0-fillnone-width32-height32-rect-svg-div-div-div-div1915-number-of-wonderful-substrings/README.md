<h2><a href="https://leetcode.com/problems/number-of-wonderful-substrings/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1915. Number of Wonderful Substrings</a></h2><h3>Medium</h3><hr><div><p>A <strong>wonderful</strong> string is a string where <strong>at most one</strong> letter appears an <strong>odd</strong> number of times.</p>

<ul>
	<li>For example, <code>"ccjjc"</code> and <code>"abab"</code> are wonderful, but <code>"ab"</code> is not.</li>
</ul>

<p>Given a string <code>word</code> that consists of the first ten lowercase English letters (<code>'a'</code> through <code>'j'</code>), return <em>the <strong>number of wonderful non-empty substrings</strong> in </em><code>word</code><em>. If the same substring appears multiple times in </em><code>word</code><em>, then count <strong>each occurrence</strong> separately.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> word = "aba"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The four wonderful substrings are underlined below:
- "<u><strong>a</strong></u>ba" -&gt; "a"
- "a<u><strong>b</strong></u>a" -&gt; "b"
- "ab<u><strong>a</strong></u>" -&gt; "a"
- "<u><strong>aba</strong></u>" -&gt; "aba"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> word = "aabb"
<strong>Output:</strong> 9
<strong>Explanation:</strong> The nine wonderful substrings are underlined below:
- "<strong><u>a</u></strong>abb" -&gt; "a"
- "<u><strong>aa</strong></u>bb" -&gt; "aa"
- "<u><strong>aab</strong></u>b" -&gt; "aab"
- "<u><strong>aabb</strong></u>" -&gt; "aabb"
- "a<u><strong>a</strong></u>bb" -&gt; "a"
- "a<u><strong>abb</strong></u>" -&gt; "abb"
- "aa<u><strong>b</strong></u>b" -&gt; "b"
- "aa<u><strong>bb</strong></u>" -&gt; "bb"
- "aab<u><strong>b</strong></u>" -&gt; "b"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> word = "he"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two wonderful substrings are underlined below:
- "<b><u>h</u></b>e" -&gt; "h"
- "h<strong><u>e</u></strong>" -&gt; "e"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists of lowercase English letters from <code>'a'</code>&nbsp;to <code>'j'</code>.</li>
</ul></div>