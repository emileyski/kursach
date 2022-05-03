using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shootable_unit : base_unit
{
    private bool x = false;
    [SerializeField] Sprite atackingBow, defaultBow;
    [SerializeField] private GameObject arrow_prefab;
    protected override void moveing()
    {
        if(!isDied)
            base.moveing();
        Vector2 direction = new Vector2(player.transform.position.x, player.transform.position.y) - new Vector2(transform.position.x, transform.position.y);
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg + 45f;
        Weapon.transform.rotation = Quaternion.Euler(angle * Vector3.forward); Weapon.transform.localScale = (player.transform.position.x > transform.position.x) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
    }
    private void FixedUpdate()
    {
        if (!isDied)
        {
            RaycastHit2D hit = Physics2D.Raycast(transform.position, player.transform.position, atackRange);
            Debug.DrawLine(transform.position, player.transform.position, Color.black);
            if (hit.collider != null && hit.collider.gameObject.tag == "Player" && x == false)
            {
                StartCoroutine("Atack", true);
            }
        }
    }
    public override void activation_deactivation(bool isActivation)
    {
        base.activation_deactivation(isActivation);
        if(isActivation)
            animator.SetBool("isWalking", true);

    }
    protected override IEnumerator Atack(bool toAtack)
    {
        animator.SetBool("isWalking", false);
        x = true;
        agent.isStopped = true;
        print("Стреляю");
        Weapon.GetComponent<SpriteRenderer>().sprite = atackingBow;
        yield return new WaitForSeconds(1f);//проигрываем анимацию(бъем)
        GameObject bullet = Instantiate(arrow_prefab, transform.position, Quaternion.identity);
        Vector2 direction = new Vector2(player.transform.position.x, player.transform.position.y) - new Vector2(bullet.transform.position.x, bullet.transform.position.y);
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;
        bullet.transform.rotation = Quaternion.Euler(angle * Vector3.forward);
        Rigidbody2D bulletRb = bullet.GetComponent<Rigidbody2D>();
        bulletRb.AddForce((player.transform.position - transform.position) * 1.5f, ForceMode2D.Impulse);
        Weapon.GetComponent<SpriteRenderer>().sprite = defaultBow;
        yield return new WaitForSeconds(cooldown);//откатываемся

        animator.SetBool("isWalking", true);
        x = false;

        agent.isStopped = false;
    }
}
