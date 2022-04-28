using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shootingMonster : unit
{
    [SerializeField] GameObject bulletPrefab;
    private GameObject Weapon;
    [SerializeField] float cooldown;
    private float x;
    protected override void Start()
    {
        base.Start();
        x = cooldown;
        Physics2D.queriesStartInColliders = false;
        Weapon = transform.Find("Weapon").gameObject;
    }
    protected override void Update()
    {
        if(isActivated)
            base.Update();
    }
    protected override void unit_moveing()
    {
        transform.localScale = (player.transform.position.x > transform.position.x) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
        Weapon.transform.localScale = (player.transform.position.x > transform.position.x) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
        if (Vector3.Distance(transform.position, player.transform.position) < atackRange)
        {
            agent.isStopped = true;
            pointing_the_bow();
        }
        else { agent.SetDestination(player.transform.position); }
    }
    private void pointing_the_bow()
    {
        Vector2 direction = new Vector2(player.transform.position.x, player.transform.position.y) - new Vector2(transform.position.x, transform.position.y);
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg + 45f;
        Weapon.transform.rotation = Quaternion.Euler(angle * Vector3.forward);
        if(cooldown != 0)
        {
            StartCoroutine("Atack");
        }
    }
    protected override IEnumerator Atack()
    {
        cooldown = 0;
        GameObject bullet = Instantiate(bulletPrefab, transform.position, Quaternion.identity);
        Vector2 direction = new Vector2(player.transform.position.x, player.transform.position.y) - new Vector2(bullet.transform.position.x, bullet.transform.position.y);
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;
        bullet.transform.rotation = Quaternion.Euler(angle * Vector3.forward);
        Rigidbody2D bulletRb = bullet.GetComponent<Rigidbody2D>();
        bulletRb.AddForce((player.transform.position - transform.position) * 2, ForceMode2D.Impulse);
        yield return new WaitForSeconds(x);
        cooldown = x;
        agent.isStopped = false;
    }
}
